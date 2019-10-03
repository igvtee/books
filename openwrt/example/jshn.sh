#!/bin/sh
. ../libubox/sh/jshn.sh 
export PATH=$PATH:../libubox

json_set_namespace JSON_TEST_

json_init
json_add_string "str" "Hello, world!"
json_add_object "obj"
json_add_int "num" "100"
json_add_boolean "bool" "0"
json_close_object
json_add_array "array"
json_add_string "arraystr" "array string"
json_add_int "" "110"
json_add_boolean "" "1"
json_close_array
MSG=`json_dump`
echo ${MSG}

json_load "$MSG"
json_get_var varstr str
json_select obj
json_get_var varnum num
json_get_var varbool bool
json_select ..
json_select array
json_get_var array1 "1"
json_get_var array2 "2"
json_get_var array3 "3"
cat << EOF
{
  msg : $varstr,
  obj: {
      num : $varnum,
      bool : $varbool
  },
  array: [ $array1, $array2, $array3 ]
}
EOF

set | grep JSON_TEST_
