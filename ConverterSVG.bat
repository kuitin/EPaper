FOR /R svg/ %F in (*.svg) do  "C:\Program Files\Inkscape\inkscape.exe" --export-png svg/%~nF25.png -w 125 svg/result/%~nF