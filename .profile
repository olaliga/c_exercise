# ShepJeng(g9401) - http://blog.shepjeng.net/
umask 002
set nu
export USERNAME=`/usr/local/bin/whoami`
#export LANG=zh_TW.UTF-8
#export LC_ALL=zh_TW.UTF-8
export TERM=xterm
export PS1="\[\033[m\][\[\033[1;36m\]\u\[\033[1;37m\]@\[\033[0;36m\]\h\[\033[37m\]]\[\033[1;32m\]\w\[\033[1;33m#\[\033[0m " 
export PS2="cont> "
export PATH=$PATH:/bin:/sbin:/usr/sbin:/usr/local/bin:/usr/bin
export CLASSPATH=$CLASSPATH:.
#export LD_LIBRARY_PATH=/usr/lib:/usr/local/lib
export EDITOR=vim
export TMOUT=1800
export PATH="/opt/csw/bin:$PATH"
#export HTTP_PROXY="http://140.119.35.51:3128"

if [ $HOSTTYPE = "sparc" ] 
then
    export PATH=$PATH:~g9401/opt/bin
    export LD_LIBRARY_PATH=~g9401/opt/lib:$LD_LIBRARY_PATH
fi


# Set alias forms
#alias ls='/usr/local/bin/ls -NF --color=auto'
alias ls='/usr/bin/ls'
alias bbs='env LC_ALL=zh_TW.BIG5 bbs'
alias vim='env TERM=xterm-color vim'
alias irssi='env TERM=xterm-color irssi'
alias ducks='du -ks * |sort -rn |head -20'
