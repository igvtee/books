
"hi comment ctermfg=Blue

"set fileencodings=utf-8
"set encoding=utf-8
"set cindent sw=4 ts=4
"set number
set makeprg=make
set paste
let mapleader = ","
filetype plugin indent on
syntax on

" 將註解由深藍色變綠色
" hi Comment ctermfg=Green

" 將註解由深藍色變淺藍色
" highlight Comment ctermfg=darkcyan

"==========================
"xml format
"==========================
map <F2> <Esc>:1,$!xmllint --format -<CR>

"==========================
"append the author infomation and date
"==========================
map <F5> a Author: Michael Lee <cr>EMail: michael_lee@alphanetworks.com <cr>Date: <C-R>=strftime("%d/%m/%Y %H:%M:%S") <CR>

"==========================
"unicode support
"==========================
if has("multi_byte")
  if &termencoding == ""
    let &termencoding = &encoding
  endif
  set encoding=utf-8
  setglobal fileencoding=utf-8
  "setglobal bomb
  set fileencodings=ucs-bom,utf-8,latin1
endif
