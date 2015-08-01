# This script demonstrates how to use Unicode file names
# in a PowerShell script.
# This script is in UTF-16 encoding.

dos2unix -i uni_el_αρχείο.txt uni_zh_文件.txt


echo "test select-string:"
dos2unix -i uni* | select-string -encoding utf8 -pattern αρχ