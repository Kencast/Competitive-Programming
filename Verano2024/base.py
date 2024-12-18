nombre=input()
destino= ''+nombre
        

with open('../template.cpp', 'r') as archivo:
    contenido=archivo.read()

with open(destino, 'w') as esc:
    esc.write(contenido)
