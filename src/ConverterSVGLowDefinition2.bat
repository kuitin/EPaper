dir /b /s svg\resultLowDef\*.* > list1.txt
::"C:\Users\Utilisateur\Downloads\lcd-image-converter-20161012\lcd-image-converter\lcd-image-converter.exe" --mode=convert-image --preset-name=Monochrome --input=C:/Users/Utilisateur/Desktop/arduino-1.8.5/libraries/DisplayEPaper/svg/result/wi-cloudy.png --output=C:/Users/Utilisateur/Desktop/arduino-1.8.5/libraries/DisplayEPaper/svg/header/wi-cloudy.c
::for /f "tokens=*" %%A in (list1.txt) do "C:\Users\Utilisateur\Downloads\lcd-image-converter-20161012\lcd-image-converter\lcd-image-converter.exe" --mode=convert-image --preset-name=Monochrome --input=svg/result/%%~nxA --output=svg/result/%%~nA.h 
::echo %%~nxA >> list.txt
G:/arduino-1.8.5/lcd-image-converter-20161012/lcd-image-converter/lcd-image-converter --mode=convert-image \
    --doc-name=test \
    --preset-name=Monochrome \
    --input=/temp/box.png \
    --output=/temp/box.c \
    --template=/temp/image.tmpl
del list1.txt

