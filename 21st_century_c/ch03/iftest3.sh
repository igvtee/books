#generate a test file
mkdir a_test_dir
echo testing ... testing > a_test_dir/tt

#Compress it, and remove only if the compression successed.
if tar cz a_test_dir > archived.tgz; then
  echo Compression went OK. Removing directory.
  rm -r a_test_dir
else
  echo Compression failed. Doing nothing.
fi
