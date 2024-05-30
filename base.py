nombre=input()
destino= 'Codeforces/CF946-3/'+nombre
        

with open('template.cpp', 'r') as archivo:
    contenido=archivo.read()

with open(destino, 'w') as esc:
    esc.write(contenido)