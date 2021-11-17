the goal is to find the hidden key: ****
you can use this command to connect to server: /ping <serverID>
example, if we have:
                  server#625
                  server#927
                  server#284

you can do 1 of these commands:
                  /ping 625
                  /ping 927
                  /ping 284

after you do the command, you have 1/3 chance to connect to the serversuccessfully

if connect to server successfully, you can see 1 of these messages: 
                  [Pinged successfully, server# reply: **** is too big]
                  [Pinged successfully, server# reply: **** is too small]
                  [Pinged successfully, server# reply: **** is the key]

when its say "**** is too big", that means the hidden key is smaller than ****
when its say "**** is too small", that means the hidden key is bigger than ****
when its say "**** is the key", that means the hidden key is ****

if can not connect to the server, it say: [You have lost connection]

you can connect to the server many times
if you know what the hidden key is, you can check by using: /confirm <yourKey>
example, if you think the hidden key is 9245, then type: /confirm 9245

if true, you win the game
else, you have to continue playing

becare: there will be a bot playing with you, if the bot know the hidden key, you will lose the game
