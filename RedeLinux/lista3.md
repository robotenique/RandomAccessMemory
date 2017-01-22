---
title:  Lista 3 - Treinamento Rede GNU/Linux
author: "Juliano Garcia de Oliveira Nº USP: 9277086"
geometry: margin=3cm
date: "26 de Janeiro, 2017"
---
###Resolução dos exercícios

####Servidores
1. O NIS é um sistema de administração e similar ao DNS, que possibilita que todos os computadores de uma rede possa acessar configurações comuns para toda a rede, centralizando o trabalho para o *host* principal. O LDAP é similar, porém é um protocolo que especifica como acessar e procurar informações em um servidor, basicamente. Por exemplo, uma rede tem 10 usuários, e será adicionado um novo usuário. Ao invés de atualizar a informação de login do novo usuário em todos os computadores da rede manualmente, usando o NIS ou o LDAP basta atualizar as informações no servidor do serviço (NIS ou LDAP). Na rede linux, e em redes de tamanho médio ou até de grande porte, o LDAP é melhor que o NIS. Enquanto o NIS é mais simples e funciona bem em LAN's pequenas, o LDAP permite uma organização melhor de informações, o *namespace* é hierárquico e a busca de informações é mais rápida e intuitiva através dos filtros que o protocolo especifica. As informações completas dos usuários de uma rede armazenados em um banco de dados central pode ser acessado e controlado através do LDAP, facilitando a consulta e a obtenção das informações.


2. O Kerberos é um protocolo de autenticação em rede, que funciona através da autenticação e troca de *tickets* entre um cliente e um serviço. O Kerberos autentica e distribui as chaves de acesso e posteriormente um *ticket* que permite um determinado cliente / usuário fazer solicitações à um determinado serviço da rede. A utilização do Kerberos em uma rede (como na Rede Linux) aumenta a segurança e simplifica várias operações e configurações. Como o Kerberos trata da autenticação através de *tickets*, ao invés de configurar manualmente quais usuários tem permissão para usar um determinado serviço, basta configurar no Kerberos, e a configuração será replicada por toda a rede. Como os acessos e identificação de um usuário funcionam a partir de um *ticket}* de acesso, o usuário não precisa ficar digitando a senha a cada serviço diferente que precisa usar, simplificando tanto para o usuário tanto para os administradores da rede que podem gerenciar os usuários e os acessos de um modo mais simples.

3. NFS é um protocolo que especifica como é feito o acesso de arquivos por usuários em uma rede. O servidor NFS dispõe de ferramentas que permitem montar discos e/ou diretórios na rede, e exportando certos diretórios para que sejam acessíveis remotamente na rede linux. --->ALTERNATIVAS <--

4. Apache é um servidor *web* HTTP. Basicamente o *Apache* recebe requisições em HTTP, analisa as requisições verificando integridade / segurança da requisição, e devolve uma página web por exemplo, caso essa tenha sido a requisição. O Apache também possui vários módulos para interpretação de diferentes linguagens, por exemplo o *php*, que é *server-side* e funciona com o *Apache*.

5. O mais comum e recomendado no linux é instalar o CUPS, que é o sistema que gerencia e controla a impressão. Ele usa o protocolo IPP, que permite compartilhamento de impressora e impressão em uma rede.  Com o CUPS, basta adicionar a impressora como um certo IP na rede e configurar o CUPS para permitir a impressão e o compartilhamento nos IP's corretos (o CUPS por padrão só permite a *loopback* e o 127.0.0.1).
