echo "<!DOCTYPE RCC><RCC version="1.0">"
echo "<qresource>"

for fi in `ls -1 *.png`
do
    echo "  <file>CardImages/$fi</file>"
done

echo "</qresource>"
echo "</RCC>"