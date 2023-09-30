import os
import glob
import shutil

os.chdir('C:\code\Mkdocs\docs')


a = glob.glob('*.md')
print(a)

def extension_converter(filename, original_extension, replacement_extension):
    head, old, tail = filename.rpartition(original_extension)
    return head + replacement_extension

for file in a:
    newfilename = extension_converter(file, '.md', '.txt')
    original = file
    target = 'textfiles\\' + newfilename
    shutil.copyfile(original, target)

    os.chdir('C:\code\Mkdocs')