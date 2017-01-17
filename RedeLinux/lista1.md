---
title:  Lista 1 - Treinamento Rede GNU/Linux
author: "Juliano Garcia de Oliveira Nº USP: 9277086"
geometry: margin=3cm
date: "26 de Janeiro, 2017"
---
###Resolução dos exercícios

1.
    a) ``` cd ../../../../var/lib/mysql/<nomeArquivo> ```

    b) Para acessar pelo caminho absoluto: ``` cd /usr/share/games/supertux/sounds/<nomeArquivo> ```. Relativamente: ``` cd ../supertux/sounds/<nomeArquivo> ```

    c) Para acessar o diretório raiz: ``` cd / ```. Uma vez no diretório raiz, não há diferença entre acessar relativamente ou absolutamente, a definição de "acessar absolutamente" é acessar relativamente ao diretório raiz.

2.
    a) A permissão para ambos os arquivos ficaria: ``` -rwx------ ```.

    b) A pasta ficaria com permissão ``` drwxrwxrwx ``` e os arquivos com permissão ``` -rwxrwxrwx ```.

    c) A pasta *www* ficaria com a permissão ``` drw-rw---- ```.

3. Usando as funcionalidades da tecla SysRq, que permite executar algumas operações na máquina, com certas combinações de teclas. Pra reiniciar é usado o ALT + SysRq + R , E , S , U , B . Cada uma dessas últimas letras se refere à uma operação diferente, pra garantir a integridade do sistema (interromper processos, dar *unmount* nas partições, etc).

4. O comando ``` touch ``` serve pra modificar a *timestamp* de um arquivo, e tem várias opções de como fazer isso (passando a data, só o último acesso, etc). Como o comando cria o arquivo quando ele não existe (a menos que se use uma *flag* específica), é bastante usado pra criar arquivos vazios.

5. Várias pastas e arquivos críticos vão ser excluídos, outros não por não ser operação permitida (mesmo  com *sudo*) . O sistema fica praticamente inutilizável depois disso. Usando a *flag -i*, o *rm* irá pedir confirmação de exclusão para cada arquivo.

6. Usar o comando *find*: ``` find / -type f -name "*MAC122*.pdf" ```.

7.
    a) Considerando que o usuário esteja na pasta *home/rickrolled*:
    - ``` chmod 700 documentos/EPs Fotos/Vihs2 www/fotodamamae.jpg ```
    - ``` chmod 755 Fotos/SouOMaximo desktop/gregoryn00b.jpg Músicas/Never Gonna Give You Up.ogg ```
    - ``` chmod g+w www ```

    b) ``` chown rflowers Fotos/Vihs2/lovelove.png Fotos/Vihs2/aikilindu.jpg ```

    c) O primeiro muda apenas adiciona a permissão de execução ao dono do arquivo, enquanto *777* garante total acesso para todos, seja ou não do grupo em questão.

8. Se tivermos acesso à conta *root*, é possível usando o comando *su*. Por exemplo, se eu quiser rodar um *script shell* no usuário *zoao*, eu faço: ````sudo su -c pasta/bot.sh zoao ```, e não preciso logar diretamente no usuário *zoao*.

10. Usando uma ferramenta chamada *crontab*, que permite agendar tarefas para serem executadas em um determinado padrão de horário e/ou data. No caso da questão, teríamos que criar um arquivo de *crontab* e então colocar a seguinte linha no arquivo : ``` 14 3 15 1-12 * <comando> ```

12.
    a) ``` apt-cache search windows ```
    b) ``` apt list --installed ```
    c) 
