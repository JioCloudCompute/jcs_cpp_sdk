for file in *h1
do
    mv -i "${file}" "${file/.h1/.h}"
done