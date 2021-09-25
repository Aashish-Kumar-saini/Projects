import speech_recognition as sr
import pyttsx3
import pywhatkit
import datetime
import wikipedia
import time as t
import pyjokes
import random
import sys
'''speech_recognition, pyttx3 for listening and speaking
    pywhat for searching, songs , datetime for telling time 
    time module for sleep(pausing program) '''

listner = sr.Recognizer()
engine = pyttsx3.init()
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[1].id)
def talk(text):
    engine.say(text)
    
    engine.runAndWait()
def take_command():
    try:
        with sr.Microphone() as source:
            talk('listening')
            print('listening...')
            voice = listner.listen(source)
            command = listner.recognize_google(voice)
            command = command.lower()
            if 'robin' in command:
                command = command.replace('robin','')
                
                
            
    except:
        pass
    
    return command

def run_robin():
    command = take_command()
    print(command)
    if 'play' in command:
        song = command.replace('play','')
        talk('playing  '+ song )
        pywhatkit.playonyt(song)
        t.sleep(30)
    
    elif 'time' in command:
        time = datetime.datetime.now().strftime('%I:%M %p')
        print(time)
        talk('Current time is '+ time)

    elif 'tell about' in command:
        item = command.replace('tell about',"")
        info = wikipedia.summary(item,2)
        print(item)
        talk(info)

    elif 'date' in command:
        x = random.randint(0,3) 
        if(x==1):
            talk('sure, hunney')
        elif(x==1):
            talk("Sorry , I don't date lossers")
        else :
            talk('Sure , on thirty first feb')
    
    elif 'are u single' in command:
        y = random.randint(0,2)
        if y==0 :
            talk(" sorry , I am committed with your WiFi ")
        elif y==1 :
            talk("Yes , wht happen ")
    elif 'tell a joke' in command:
        talk(pyjokes.get_joke())

    elif 'stop' in command:
        sys.exit()
        
    else:
        talk('Please say again')


while True:
    run_robin()