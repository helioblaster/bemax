# Manual de uso

> - Breve Resumo: Se trata de um totem de consulta para o funcionário, o objetivo desse totem é servir de apoio ao funcionário ao longo de sua jornada semanal de de trabalho. Basicamente o totem possui duas funcionalidades...
1. Um sensor de batimento cárdiaco (modelo max 30102)
2. Um Sensor de ruído acoplado a uma led que acende em vermelho com muito barulho (modelo ky-037 e WS2812 respectivamente)

## Projeto: BenMax Totem

> Para os interessados em replicar o nosso projeto em um momento futuro

## Segue a lista dos produtos usados ao longo desse projeto

- Tela LSD 20x4
- Sensor de batimento cardiaco modelo max30102
- Detector de som microfone modelo ky-037
- Anel RGB modelo WS2812
- Suporte Porta 4 Pilhas
- Kit de Arduíno completo com todas as peças (isso é essencial)
- Filamento de plástico PLA para o molde (opicional)

## Procedimento passo a passo
> A montagem foi feita em várias etapas e cada parte essencial sera citada abaixo
- OBS: O código ultilizado no aplicativo Arduíno IDE está nesse GitHub

## 1. Tela LSD 20x4
- Para a montagem inicial dessa tela você vai precisar de uma protoboard, com dois fios ligados, 1 ao GND (grounded) e o outro a energia (5V).
- Conecte quatro fios a tela LSD sendo eles o GND (grounded), VCC (5V), o SDA (coloque na porta de entrada A4) e o SCL (coloque na porta A5)
- Lembrando que não é necessário colocar registores

## 2. Sensor de batimento cardiaco (max30102)
- Esse sensor já vem com os 3 fios juntos a ele (não é necessário fazer um encaixe)
- O fio preto (polo negativo) conecta-se ao (GND)
- O fio do meio (vermelho) conecta-se a entrada de energia de (5V)
- O fio Restante (amarelo) conecta-se a porta de entrada (A1)
- Caso seja emitida uma luz verde do sensor, ele já é funcional

## 3. Detector de som microfone (ky-037)
- Esse sensor vem com 4 entradas (vão ser usadas 3 delas)
- Coecete um fio ao (G) e depois coloque ele no (GND)
- Cocecte um fio ao (+) e depois conecte ele no (5V)
- Conecte um fio ao (A0) do própio sensor e depois coloque ele na entrada (A0)
- Após isso, se o sensor emitir uma luz vermelha, já estara apto a funcionamento

## 4. Anel RGB (WS2812)
- Esse sensor vem sem nenhum fio (é necessário a solda feita a mão)
- Só é necessário usar as portas (DI), (5v) e (GND) do Anel RGB
- Após a solda, conecte o (DI) a entrada 6 (com linha tracejada)
- Conecte respectivamente os fios (5V) ao fio vermelho do Suporte de 4 pilhas e o (GND) ao (GND)
- Após isso, se acender uma luz brilhando em verde, estará apto ao funcionamento

## 5. Suporte Porta 4 Pilhas
- As pilhas usadas são AA de 1.5 volts
- O Suporte tem dois fios, preto e vermelho
- O vermelho Vai conectado ao Anel RGB no fio dos (5V)
- O preto (2 fios) vai conectado ao (GND) e ao (5V)

## 6. Como usar
- Após todo esse processo de montagem você fará o seguinte
- Coloque o dedo no sensor (parte circular brilhando em verde), se ouver variação na tela com relação ao valor do BPM é porque está funcionando
- Com relação ao sensor de ruído, bata palmas ou grite perto da ponta do sensor, se a luz mudar de verde para vermelha é porque está funcionando

## Agradecimentos
> Esse projeto foi feito por um grupo de estudantes da faculdade da Cesar School durante o seu 1° período de barcharelado, a seguir estão os nomes do envolvidos nesse projeto
- Clara Sampaio - DSG
- Hélio de Moraes - CC
- João Pedro Barbosa - CC
- Joel Costa Oliveira - CC
- Luis Filipe - CC
- Marcus Vinícius Pereira - CC
- Vinicius Pastich - CC
- Victor Rodrigues - CC
- Ellen de Oliveira - DSG
