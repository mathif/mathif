<div style="width:1000px; margin:0 auto;">

<center> 
# Week 1

# Principles and Practices 

</center>



## Lecture video

Link to the [video lecture](https://vimeo.com/fabacademy/videos)

> [Introduction Principles and Practices](https://vimeo.com/153262283)

> [Lesson-1 Project Management](https://vimeo.com/153263942)

--------------

## Assignment

Documentation is very important in fab Academy. I used to create my daily documentation by Markdown. I created html and push to Gitlab by using some help of  steps that listed in sub topics.

-------------

### Markdown Documentation


Markdown is a way to write content for the web. To know more about Markdown click the link [here](http://markdowntutorial.com/)

#### Install Retext

Open terminal window

`
    sudo apt-get install retext   
`

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


###  Gitlab <img src="img/w2.png" width="30"/>

#### Installing git

To install git in Ubuntu type in a terminal window:



`sudo apt-get install git
`

#### Add SSH keys to your system

Use a SSH connection that requires SSH keys for pulling and pushing the documentation. For download Click the link [here](file/fab2016.zip) 

Download and unzip the keys and move them to your ~/.ssh folder. Finally set permissions on the private key:

```
    mv fab2016 ~/.ssh
    mv fab2016.pub ~/.ssh
    chmod 600 ~/.ssh/fab2016
```

And now add the keys to the system:

```
    eval "$(ssh-agent -s)"
    ssh-add ~/.ssh/fab2016
```

#### Clone the repository

 Inside a terminal window, navigate to where you want to clone the repository:
 created a folder named as fabacademy. Open in terminal 
 
```
     git clone git@git.fabacademy.org:fabacademy2016/fablabkochi.git
     
```
 
#### Configuring git

Set some basic config and tell git who you are. , but replaced yourname with my actual name and youremail with my email address.

```
    git config --global user.name "myname"
    git config --global user.email "myemail"
    git config --global push.default simple
```
#### Basic git workflow

TUpload those changes to the repository. Very important: Do not miss any step, and do them in order.

```          
    git pull                 
    git add --all             
    git commit -m "message" 
    git push
```
-------------





</div>
