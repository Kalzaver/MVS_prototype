import sys
import json
from docx import Document

def mass_replace(json_path, docx_path):
    print("\n=== Замена начата ===")
    with open(json_path, 'r', encoding='utf-8') as f:
        replacements = json.load(f)

    doc = Document(docx_path)

    # Функция замены с объединением текста параграфа (решает проблему разбиения на runs)
    def replace_in_paragraph(paragraph):
        full_text = ''.join([run.text for run in paragraph.runs])
        new_text = full_text
        for key, value in replacements.items():
            new_text = new_text.replace(key, str(value))
        if new_text != full_text:
            # Заменяем текст в первом run, остальные очищаем
            if paragraph.runs:
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
    print("=== Замена завершена ===\n")

if __name__ == "__main__":
    u_json_path = "C:/treeFrogProject/myapp/wordtempl/breedTemplates/data_from_web.json"
    u_copy_file_path = "C:/treeFrogProject/myapp/wordtempl/breedTemplates/copy_template.docx"

    mass_replace(u_json_path, u_copy_file_path)