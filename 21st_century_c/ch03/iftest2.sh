if [ ! -e a_test_file ]; then echo test file had not exists;
  touch a_test_file; else echo test file existed; rm a_test_file; fi
