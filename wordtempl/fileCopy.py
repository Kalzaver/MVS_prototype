import configparser
import os
from docx import Document

INI_PATH = r'C:/treeFrogProject/myapp/config.ini'

def copy_file(orig_file_path, copy_file_path):
    doc = Document(orig_file_path)
    doc.save(copy_file_path)
    print("================ \n" + "copying finished \n" + "================ \n")


if __name__ == "__main__":
    config = configparser.ConfigParser()

    if not os.path.exists(INI_PATH):
        print(f"ОШИБКА: Файл конфигурации не найден по адресу: {INI_PATH}")
        exit(1)

    # Читаем конфиг (секция [TemplateBreed])
    config.read(INI_PATH, encoding='utf-8')

    try:
        # Берём пути из соответствующих ключей в ini
        u_orig_file_path = config['TemplateBreed']['template']
        u_copy_file_path = config['TemplateBreed']['copy']

        copy_file(u_orig_file_path, u_copy_file_path)

    except KeyError as e:
        print(f"ОШИБКА: В ini-файле не найден ключ: {e}")
    except Exception as e:
        print(f"ПРОИЗОШЛА ОШИБКА: {e}")
