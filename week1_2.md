<div style="width:1000px;">


## Website Devlopment And Documentaion


### Mecurial  

Mercurial is a fast, lightweight Source Control Management system designed for the efficient handling of very large distributed projects. Mercurial is a cross-platform, distributed revision control tool for software developers.Tutorial which covers how to install Mercurial on Ubuntu and clone the Fab Academy archive helped me to install mercurial. To communicate with the Fab Academy server in order to clone and communicate with the shared archive we should need SECURE SHELL.

To install secire shell.

open terminal

```
    sudo apt-get install ssh
```   

Then to instal Mercurial

```
    sudo apt-get install mercurial
```
[Installing Mercurial on Ubuntu](http://fabacademy.org/archives/2015/doc/mercurial_install_ubuntu.html)  

### GitHub

#### Create a Github account using your email ID.

Open the Terminal application.

#### [Install Git](http://git-scm.com/downloads) 

```
    sudo apt-get install git   
```

#### [Configure git](https://help.github.com/articles/set-up-git/)

```
    git config --global user.name "YOUR NAME"

    git config --global user.email "YOUR EMAIL ADDRESS"

```
#### [Create a repository](https://pages.github.com/)

create a new repository named username.github.io, where username is your            username on GitHub

#### Clone the repository

Go to the folder where you want to store your project, and clone the new    repository:
```
    git clone https://github.com/username/username.github.io
```

Enter the project folder and add an index.html

```
    cd username.github.io
    echo "Hello World" > index.html

```

#### HTTPS link vs SSH link([Creating SSH keys](https://help.github.com/articles/generating-ssh-keys/) )

#### [Change from HTTPS to SSH](https://help.github.com/articles/changing-a-remote-s-url/) 
Workflow for Pulling and pushing

```
    git pull
    git add --all
    git commit -m “message”
    git push
```
[Conflicts](https://help.github.com/). Do’s and Don'ts

 </div>