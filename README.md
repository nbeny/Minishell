# Minishell

[cd]
1.cd -
2.unsetenv PWD
cd
result[segmentation fault]

leaks
cd relatife/path

command qui commence avec des clashs
ex: /bin/ls

commands qui commence avec des espaces et \t
faut les enlever !!!!


unsetenv PATH
[segfault]

setenv PATH [un truc illegal]
[abort]

env -i ./minishell
setenv FOO bar
env
result: on voit rien

[leaks]
1.sesenv


env -i OLDPWD=/ ./minishell
env
result = segfault
