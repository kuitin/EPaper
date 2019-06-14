dir /b /s svg\*.* > list1.txt

for /f "tokens=*" %%A in (list1.txt) do "C:\Program Files\Inkscape\inkscape.exe" --export-png svg/resultLowDef/%%~nA.png -w 30 -background 255 svg/%%~nxA
::echo %%~nxA >> list.txt

del list1.txt
