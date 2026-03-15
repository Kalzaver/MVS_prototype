import json
import configparser
import os
from docx import Document

INI_PATH = r'C:/treeFrogProject/myapp/config.ini'

def mass_replace(json_path, docx_path):
    print(f"\n=== Замена начата ===")

    with open(json_path, 'r', encoding='utf-8') as f:
        replacements = json.load(f)

    doc = Document(docx_path)

    def replace_in_paragraph(paragraph):
        # Собираем текст из всех «прогонов» (runs) параграфа
        full_text = ''.join([run.text for run in paragraph.runs])
        new_text = full_text
        for key, value in replacements.items():
            new_text = new_text.replace(str(key), str(value))

        if new_text != full_text:
            if paragraph.runs:
                # Записываем новый текст в первый run, остальные очищаем
                paragraph.runs[0].text = new_text
                for run in paragraph.runs[1:]:
                    run.text = ''

    for para in doc.paragraphs:
        replace_in_paragraph(para)

    for table in doc.tables:
        for row in table.rows:
            for cell in row.cells:
                for para in cell.paragraphs:
                    replace_in_paragraph(para)

    doc.save(docx_path)
    print(f"=== Замена завершена. Файл сохранен: {docx_path} ===\n")


if __name__ == "__main__":
    config = configparser.ConfigParser()

    # Проверяем, существует ли файл по указанному пути
    if not os.path.exists(INI_PATH):
        print(f"ОШИБКА: Файл конфигурации не найден по адресу: {INI_PATH}")
        exit(1)

    # Читаем конфиг
    config.read(INI_PATH, encoding='utf-8')

    try:
        # Извлекаем пути из секции [TemplateBreed]
        json_file = config['TemplateBreed']['json']
        docx_file = config['TemplateBreed']['copy']

        mass_replace(json_file, docx_file)

    except KeyError as e:
        print(f"ОШИБКА: В ini-файле отсутствует ключ или секция: {e}")
    except Exception as e:
        print(f"ПРОИЗОШЛА ОШИБКА: {e}")
