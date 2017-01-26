---
title:  Lista 2 - Treinamento Rede GNU/Linux
author: "Juliano Garcia de Oliveira Nº USP: 9277086"
geometry: margin=3cm
date: "26 de Janeiro, 2017"
---
###Gerenciamento de usuários e grupos

1. O comando *adduser* permite adicionar usuários, podendo ser especificado o grupo, a *shell* que o usuário vai usar, o diretoŕio *home*, etc.

2. Sim, é o comando *addgroup*, que é bastante similar ao *adduser*, permitindo algumas personaliações na hora de criar um grupo no linux.

3. Para criar o grupo, basta editar */etc/group* e adicionar uma nova linha, por exemplo *metallica:x:890:*. Para criar o novo usuário, precisa editar */etc/passwd*, adicionando uma nova linha com os dados do usuário em questão: *lars:x:890:890:lars,,,:/home/lars:/bin/bash*, criar a *home* usando *mkdir*, copiar os arquivos relacionados com a *shell* de */etc/skel/* para a *home* do usuário, e consertar as permissões da *home* do usuário usando *chmod* e *chown*. Por fim, é só definir uma senha para o usuário com o comando *passwd*.

4. O *script* usa a biblioteca *subprocess*, e funciona na versão 3.5 do *python*. -->ADD SENHAA<==
```python
import string
import random as rnd
from subprocess import *
print("==> New user creator -> RUN WITH 'SUDO python newUser.py'!\nINFO:Be sure that the username doesn't exist by checking it first in /etc/passwd!")
username = input("Type the username:")
Popen(['sudo','groupadd',username])
Popen(['sudo','useradd',"-g", username, username])
ps = Popen(('sudo', 'passwd', '--'), stdout=subprocess.PIPE)
output = subprocess.check_output(('grep', 'process_name'), stdin=ps.stdout)

st = string.ascii_letters + string.digits
pw = "".join((rnd.choice(st)) for x in range(10))
Popen(['sudo','passwd',"-g", username, username])
print("The user was created. You password is: ", pw)
```
5. Sim, usando o pacote *libpam-cracklib*. Ao instalar esse pacote, podemos configurar a segurança mínima da senha, no arquivo */etc/pam.d/common-password*, que possui várias opções pra aumentar a segurança e complexidade da senha.

6. Usando o comando *id -Gn username*. Ele irá mostrar todos os grupos que um certo usuário está.

####Inicialização do Sistema
1. *init* é um processo que é iniciado no *boot* do sistema. Ele é iniciado assim que o *kernel* é carregado, e passa a ser o pai de todos os processos que são iniciados posteriormente. O *init* lê vários arquivos de inicialização e executa diversos *scripts* que cuidam das configurações básicas na inicialização, como ajustar os horários, iniciar os serviços, interfaces de rede, etc.

2. Usando o *cron* e especificando *@reboot* no arquivo *crontab*, que o comando será executado no *boot*. Também é possível criar um *script* no *init.d* (que deve seguir uma sintaxe diferente de um *script* qualquer).

3. *Daemons* são processos que não são interativos com diretamente, que são executados em *background* e respondem dependendo de certas condições, por exemplo uma certa data, ou uma requisição de uma outra aplicação. Para inicializar um *daemon* na inicialização do sistema são executados *scripts* que estão na pasta */etc/init.d/*. Um *daemon* também pode ser inicializado com o comando *service daemon start*.

####Gerenciamento de dispositivos
1. Uma partição é simplesmente uma divisão em uma unidade de armazenamento. O particionamento separa os discos em unidades lógicas diferentes, que podem ter sistemas de arquivos diferentes. No linux, cada partição é mostrada como se fosse um *device* diferente em */dev*.

2. Ficam localizados em */dev*.

3. O comando *fdisk*, executado como *root*. Primeiramente, listar os discos com *fdisk -l*, em seguida entrar no modo interativo com *fdisk /dev/momeDisco*. Para deletar a partição é simplesmente *d*
, para adicionar uma nova *n*, e assim por diante. No final, falta escrever as operações com *w*.

4. Partições primárias são partições comuns de disco, e é onde se deve instalar o sistema linux. As partições lógicas são subpartições de uma partição primária, sendo que a partição primária que possui essas subpartições tem um formato diferente das partições primárias comuns. É possível criar várias partições lógicas, mas o número de partições primárias é limitado. Partições de SWAP são usadas para manter parte da memória RAM no disco do sistema, quando a memória RAM está sendo muito utilizada e precisa de mais espaço. É uma espécie de memória emergencial quando a RAM está muito cheia, mas é bem mais lento por se tratar de um disco, e não de uma memória RAM propríamente dita.

5. o *Mount Point* é o diretório raiz que permite acessar todos os outros arquivos de uma partição do disco.

6. Para montar uma partição, pode-se usar o comando *mount* ou então a ferramenta *udiskctl*, por exemplo para montar /dev/sdc2, basta rodar *udisksctl mount -b /dev/sdc2*. Para desmontar é mais simples, basta usar o *umount*, por exemplo *umount /dev/sdc2*. Lembrando que o *mount* e *umount* precisam ser executados como *root*.

7. O comando *fsck* é usado para verificar a consistência de arquivos do sistema (no linux é o *filesystem(ext2)*), além de fazer reparos. É bastante utilizado pra tentar recuperar sistemas linux que estão corrompidos, ou algum problema relacionado com o disco. Sim, é possível executá-lo durante o *boot*, e ele é automaticamente executado na maioria dos sistemas linux após um certo número de *boots* para verificar integridade do disco antes da inicialização do sistema.

####Gerenciamento de processos
1. Processo é simplesmente um programa em execução.

2. Um processo e identificado através do seu ID, o *PID*. Um processo também possui informações do usuário e grupo para o qual o processo está sendo executado, através do *uid* e *gid*. Um processo também possui um estado, mas esse atributo não o identifica unicamente no sistema.

3. Um processo pode estar rodando no sistema normalmente ou pronto para a execução, em ambos esses casos está no estado *running*. Um processo que está esperando um evento está no estado *waiting*. O evento pode ser várias coisas, como um arquivo, um sinal do sistema, um recurso ficar disponível, uma porta não estar mais ocupada ou até eventos do *hardware*. Processos que estão parados estão no estado *stopped*, e finalmente há os processos que estão no estado *zombie*, que é um processo morto (ou seja, já executou a operação) mas ainda está listado nos processos do sistema.

4. No primeiro caso o *vim* será executado no modo interativo, enquanto no segundo o operador *&* faz com que o processo do vim seja executado em *background*.

5. Como explicado na questão anterior, basta usar o *&* no final do comando, ou então executar o comando e apertar CTRL + Z, que coloca o processo em *background*.

6. Para colocar um programa que está *foreground* em *background* basta apertar CTRL + Z. Para fazer o contrário, basta digitar *jobs* para aparecer a lista dos processos, e então rodar o comando *fg %x*, substituindo o 'x' pelo número do processo que deve voltar para *foreground*. Se nenhum número for especificado, o último processo a ser colocado em *background* que irá voltar para *foreground*;

7. Usando o comando *top* ou *htop* se disponível. Também é possível através do comando *ps*.

8. Abrir um gerenciador como o *top* ou *htop*, achar o processo que está consumindo os recursos, e então enviar um sinal SIGTERM para o processo, ou até mesmo SIGKILL se não for possível terminar com o SIGTERM.

9. Executar o comando *killall -u malvadeza*.

10. É um *fork bomb*. O comando cria a função que chama a si mesma, e então chama essa função uma primeira vez.

11. Sim, através de uma funcionalidade chamada *cgroups*. Com ela é possível configurar limites para o uso de memória RAM, uso de CPU, etc.

####Links
1. Os *soft links* são ponteiros para um arquivo. Eles são usados para redirecionar e apontar para um arquivo em outro lugar no disco. Para criar um link simbólico basta usar o comando *ln -s \<nomeArquivoOuPasta\> \<nomeDoLink\>*.

2. A diferença é que o *hard link* sempre aponta para o arquivo enquanto ele existir, não importa se ele foi movido para outro lugar, enquanto o *soft link* não irá apontar mais para o arquivo se ele foi movido após a criação do *link* em questão.

3. a) Não, apenas o ponteiro é removido, o arquivo permanece inalterado.

   b) O padrão do comando *cp* é copiar o arquivo apontado pelo *soft link*, não o *soft link* em si. Para copiar o *soft link* usa-se a opção *-h*.

   c) Por *default* o comando *tar* copia o *soft link*. Para fazer com que copie um arquivo deve ser usado a *flag -h*.

####SSH
1) Sim, usando uma chave RSA de ssh. Basta rodar o comando *ssh-keygen*, seguir os procedimentos, e quando a chave já estiver sido gerada, basta usar *ssh-copy-id user@dominio*, que a chave será transferida. Assim, é possível logar sem ter que ficar digitando a senha sempre.

2.
