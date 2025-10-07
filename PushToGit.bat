@echo off
cd C:\Projects\Wordpasser
git add .
set /p "Message=Enter commit message:"
git commit -m %Message%
git push
echo Done!
timeout /t 3 /nobreak>nul
