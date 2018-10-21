if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <Nul>  
nnoremap <silent>  a :call feedswitch#Run()
nnoremap <silent>  f :call feedlist#File()
nnoremap <silent>  l :call feedlist#Buffer()
nnoremap  e :edit %
nnoremap  q :qa
nnoremap  s :silent! grep -w ''<Left>
nnoremap , ;
nnoremap ; :
nmap \  
inoremap  
inoremap  
inoremap jk 
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set background=dark
set backspace=indent,eol,start
set cindent
set cinoptions=c0,C1,(1s,U1,t0
set completeopt=
set dictionary=~/.vim/dict/web2
set diffopt=filler,foldcolumn:0,vertical
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set fillchars=stlnc:â€•,stl:â€•,vert:â”‚,fold:â‹…,diff:â‹…
set grepprg=grep\ -n\ -i\ -r\ --exclude-dir=.git\ --exclude=tags\ --exclude=_obj*\ $*\ .
set guicursor=n-v-c:block,o:hor50,i-ci:hor5,r-cr:hor30,sm:block
set helplang=En
set hidden
set history=500
set hlsearch
set ignorecase
set incsearch
set lazyredraw
set listchars=tab:â‹…â‹…,trail:â‹…
set path=.,/usr/local/include,/usr/include
set printoptions=paper:letter
set ruler
set runtimepath=~/.vim,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim80,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after
set shell=sh
set shiftround
set shiftwidth=4
set shortmess=atToOsI
set showtabline=0
set smartindent
set softtabstop=4
set nostartofline
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set noswapfile
set ttimeoutlen=100
set visualbell
" vim: set ft=vim :
