import speech_recognition as sr

r = sr.Recognizer()
while True:
    with sr.Microphone() as source:
        print("Say Something!")
        audio = r.listen(source)

    try:
        print("You said: " + r.recognize_google(audio))
    except sr.UnknownValueError:
        print("Nao entendi!")
    except sr.RequestError:
        print("Nao conectei no google")
