<div style="width:800px;">

<font color="#003300">

## Website Devlopment And Documentaion
</font>

<font color="#000066">

### Mecurial  
</font>

<div align="justify;" style="margin-left:2.5%" style="margin-right:2.5%">

Mercurial is a fast, lightweight Source Control Management system designed for the efficient handling of very large distributed projects. Mercurial is a cross-platform, distributed revision control tool for software developers.Tutorial which covers how to install Mercurial on Ubuntu and clone the Fab Academy archive helped me to install mercurial. To communicate with the Fab Academy server in order to clone and communicate with the shared archive we should need SECURE SHELL.

To install secire shell.

open terminal

<font color="#585858">

```
    sudo apt-get install ssh
```   

</font>

Then to install Mercurial

<font color="#585858">

```
    sudo apt-get install mercurial
```

</font>

For more details to Installing [Mercurial](http://fabacademy.org/archives/2015/doc/mercurial_install_ubuntu.html) on Ubuntu  

</div>
<font color="#000066">

### GitHub

</font>

#### Create a Github account using your email ID.
<div align="justify;" style="margin-left:2.5%" style="margin-right:2.5%">

Open the Terminal application.
</div>

#### [Install Git](http://git-scm.com/downloads) 

<div align="justify;" style="margin-left:2.5%" style="margin-right:2.5%">

<font color="#585858">

```
    sudo apt-get install git   

```

</font></div>

#### [Configure git](https://help.github.com/articles/set-up-git/)

<div align="justify;" style="margin-left:2.5%" style="margin-right:2.5%">
<font color="#585858">

```
    git config --global user.name "YOUR NAME"

    git config --global user.email "YOUR EMAIL ADDRESS"

```             
</font></div>

#### Create a repository
<div align="justify;" style="margin-left:2.5%" style="margin-right:2.5%">

create a new [repository](https://pages.github.com/) named username.github.io, where username is your username on GitHub
</div>

#### Clone the repository
<div align="justify;" style="margin-left:2.5%" style="margin-right:2.5%">

Go to the folder where you want to store your project, and clone the new    repository

<font color="#585858">

```
    git clone https://github.com/username/username.github.io
```
</font>

Enter the project folder and add an index.html

<font color="#585858">

```
    cd username.github.io
    
    echo "Hello World" > index.html

```
</font></div>


#### HTTPS link vs SSH link([Creating SSH keys](https://help.github.com/articles/generating-ssh-keys/) )

#### Change from [HTTPS to SSH](https://help.github.com/articles/changing-a-remote-s-url/) 

<div align="justify;" style="margin-left:2.5%" style="margin-right:2.5%">

Workflow for Pulling and pushing

<font color="#585858">

```
    git pull
    git add --all
    git commit -m “message”
    git push
```
</font></div>

[Conflicts](https://help.github.com/). Do’s and Don'ts

 </div>