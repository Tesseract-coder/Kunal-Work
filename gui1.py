import Tkinter as tk
import cv2
import numpy

class GUI(tk.Tk):
    def __init__(self):
        tk.Tk.__init__(self)

        bF = tk.Frame(self, bd=8, relief='sunken')
        bF.pack(expand='true', fill='x')
        Button1 = tk.Button(bF, text='Basic', bd=4, fg='white',relief='groove', activebackground='green',command=self.basic)
        Button1.pack()
        Button2 = tk.Button(bF, text='Email', bd=4, fg='white',relief='groove', activebackground='green',command=self.Email)
        Button2.pack()
        Button3 = tk.Button(bF, text='parking', bd=4, fg='white',relief='groove', activebackground='green',command=self.SMS)
        Button3.pack()        

    def basic(self):
        execfile('/home/pi/project/project1.py')
        key = cv2.waitKey(10)
        if key == 27:
            cv2.destroyAllWindows

    def Email(self):
        execfile('/home/pi/project/project2.py')        
        key = cv2.waitKey(10)
        if key == 27:
            cv2.destroyAllWindows
    def SMS(self):
        
        execfile('/home/pi/project/project4.py')
        key = cv2.waitKey(10)
        if key == 27:
            cv2.destroyAllWindows
        
gui = GUI()
gui.mainloop()
