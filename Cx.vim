
syntax match Parentheses '".*"'
syntax keyword Keywords Inline Traits Struct Namespace Using Class Enumerator
syntax keyword C_Words static void int bool unsigned char reserved volatile size_t return NULL PyObject 
syntax keyword LogicWords while do if switch case else

syntax match TypeAccessor /@\S\+/ 
syntax match TraitDeclaration /@!\S\+/
syntax match Numbers /[0-9]/

highlight TypeAccessor ctermfg=green
highlight TraitDeclaration ctermfg=yellow

highlight Parentheses ctermfg=DarkMagenta
highlight LogicWords ctermfg=yellow
highlight Numbers ctermfg=Magenta
highlight Operators ctermfg=white
highlight Keywords ctermfg=blue
highlight C_Words ctermfg=blue

highlight Comment ctermfg=white
