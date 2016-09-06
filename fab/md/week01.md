title: week-1
tags: ["handlebars", "template"]
---


# Week-1: Principles and Practices 

-------------

## Lecture video

Link to the [video lecture](https://vimeo.com/fabacademy/videos)

> [Introduction Principles and Practices](https://vimeo.com/153262283)

> [Lesson-1 Project Management](https://vimeo.com/153263942)

---------

[Link to my final project proposal](project.html)

--------------

## Assignment

Documentation is very important in fab Academy. I used to create my daily documentation by Markdown. I created html and push to Gitlab by using some help of  steps that listed in sub topics.

-------------

### Markdown Documentation


Markdown is a way to write content for the web. To know more about Markdown click the link [here](http://markdowntutorial.com/)

#### Install Retext

Open terminal window

<pre>
sudo apt-get install retext   
</pre>

When you install the rext create an empty document and rename it in the format (index.md).


<center><img src="gif/g1.gif" width="500"/></center>

Open the index.md file in with retext.

Write the comtent that you want to document and save it.

#### Install Pandoc

Open terminal window.

`
    sudo apt-get install pandoc
`

Then to convert the .md document to .html use this commment in terminal

Eg: to convert the index.md to index.html

`
    pandoc -s -o index.html index.md
`

---------------


### Gitlab 

#### Installing git

Git is a distributed vertion control.

<center><img src="img/w1/version-control-fig3.png" width="500"/></center>


To install git in Ubuntu type in a terminal window:



`sudo apt-get install git
`

#### Add SSH keys to your system

Use a SSH connection that requires SSH keys for pulling and pushing the documentation. For download Click the link [here](file/fab2016.zip) 

Download and unzip the keys and move them to your ~/.ssh folder. Finally set permissions on the private key:


    mv fab2016 ~/.ssh
    
    mv fab2016.pub ~/.ssh
    
    chmod 600 ~/.ssh/fab2016


And now add the keys to the system:



    eval "$(ssh-agent -s)"

    ssh-add ~/.ssh/fab2016

Or

go to *git.fabacademy.org* and add shh key .. u can see help there..

open the teminal and type the commends. for checking exist on your PC.

<center><img src="img/w1/git1.png" width="800"/></center>

if you Don't have.. type the comment for generating the shh key..

<center><img src="img/w1/git2.png" width="800"/></center>

for showing the key . type the commend. copy and past it on the git account and save it.

<center><img src="img/w1/git3.png" width="1000"/></center>



#### Clone the repository

 Inside a terminal window, navigate to where you want to clone the repository:
 created a folder named as fabacademy. Open in terminal 

     git clone git@git.fabacademy.org:fabacademy2016/fablabkochi.git


<center><img src="img/w1/gitclone.png" width="800"/></center>

 
#### Configuring git

Set some basic config and tell git who you are. , but replaced yourname with my actual name and youremail with my email address.

    git config --global user.name "myname"
    
    git config --global user.email "myemail"
    
    git config --global push.default simple
    
    
#### Basic git workflow

TUpload those changes to the repository. Very important: Do not miss any step, and do them in order         
    
    git pull 
                    
    git add --all 
                
    git commit -m "message" 
    
    git push

-------------


## Final project? What I am going to do..


### Frist Idea: Smart Component Manager

#### The challenge

Here in our lab when you listed the needs like resistor, ic, capacitor,  in a paper the searching is the big challenge. So, I am planned to solve the challenge using some cheap and simple components. 



<center><img src="img/p1.jpg" width="400"/></center>

#### The Plan

The challenge how I going to solve with an Arduino board, Servo motors, LED, push button etc.. the servo motor connected the box. by which changing of polarity can make to and fro motion. A readymade list on the side of the box, from there, can select the needed components using push button that time the LED blinks. after selecting the all consumables press the enter button. the time all boxes which containing the consumables get open. for closing the box press the button back. 

<center><img src="img/p3.jpg" width="200"/> <img src="img/p4.jpg" width="400"/></center>

---------

### Second Idea: Blind snooper

This device which navigates the blind people. Using microcontroller, ultrasonic sensor, vibrator, push button. This will sense the obstacle and measure the distance it changes the vibrating frequency depend on upon obstacle.


---------------


