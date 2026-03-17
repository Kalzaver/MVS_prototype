# fileCopy.py (обновленный)
import configparser
import os
import sys
from docx import Document

INI_PATH = r'C:/treeFrogProject/myapp/config.ini'

def copy_file(orig_file_path, copy_file_path):
    try:
        doc = Document(orig_file_path)
        doc.save(copy_file_path)
        print(f"Копирование завершено: {copy_file_path}")
    except Exception as e:
        print(f"ОШИБКА копирования: {e}")


# ... начало файла как у вас ...

if __name__ == "__main__":
    section_name = "TemplateBreed"
    if len(sys.argv) > 1:
        section_name = sys.argv[1]

    config = configparser.ConfigParser()
    # ... проверка существования и read ...
    config.read(INI_PATH, encoding='utf-8')

    try:
        u_orig_file_path = config[section_name]['template']
        u_copy_file_path = config[section_name]['copy']
        copy_file(u_orig_file_path, u_copy_file_path)
    except KeyError as e:
        print(f"ОШИБКА: В ini-файле не найден ключ для секции {section_name}: {e}")
    except Exception as e:
        print(f"ПРОИЗОШЛА ОШИБКА: {e}")