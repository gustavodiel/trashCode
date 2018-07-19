import getpass
import requests

URL = "https://siga.udesc.br/sigaSecurityG5/?pcaes=a205de9c60d3992e6296830743168a74"

session = requests.session()

# user = input("User: ")
# pw = getpass.getpass("Password: ")

data = {
        'initialURI': '',
        'action': 'formLogin',
        'j_username': '10822574942',
        'senha': 'G.D.hiper101112' }
res = session.post(URL, data=data)
print (res.status_code)

req = session.get('https://siga.udesc.br/siga/com/executaconsultapersonaliz.do?evento=executaConsulta&id=2&exe=S', stream=True)
with open('teste.html', 'w') as f:
    f.write(req.content)

print(req.headers)
print(req.text)
print (req.content)
