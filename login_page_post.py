import getpass
import requests

URL = "http://moodle2.joinville.udesc.br/login/index.php"

session = requests.session()

user = input("User: ")
pw = getpass.getpass("Password: ")

data = {
        'initialURI': '',
        'action': 'login',
        'username': user,
        'password': pw }
res = session.post(URL, data=data)
print (res.status_code)

req = session.get('http://moodle2.joinville.udesc.br/pluginfile.php/2296/mod_resource/content/39/TEG_parte_IV_V2.0.pdf', stream=True)
with open('teste.pdf', 'wb') as f:
        for chunk in req.iter_content(chunk_size=1024):
                if chunk:
                        f.write(chunk)

#print(req.headers)
#print(req.text)
#print (req.content)

