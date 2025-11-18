Git crash course (for Nate and Mateo)

first clone the repo, go to the directory/folder you want the repo in then type (in the terminal):
git clone https://github.com/AshtonVang001/parkour_game.git

After you clone go into the parkour_game directory by doing: cd parkour_game
You now have all the code and this directory is already initialized to the remote repo, you can check by doing git status
Also when pushing, pulling, or branching out, always make sure you are in the parkour_game directory

Currently you are in the main local branch

What are branches?
A branch is basically a workspace. You are currently in your main local branch and github has the main remote branch.

What is the difference between local and remote branches?
Your local branch is the branch you are currently editing and making changes to your code. The remote branch is in github.
You will push your code to the remote branch.

When we start coding we are going to want to branch out when making different features

What is branching out?
It is essentially making a new branch outside of the main branch. 

Why do you want to branch out?
The reason we want to branch out is so we can isolate code. We don't each have to constantly push our code to main. We would
just push our code to our own branches then merge the code to main later. Another reason we branch out is so we don't override 
eachothers code, again isolation. Another reason why we branch out is because our main branch is supposed to have our working 
application. For example lets say you are working on a new feature so you create a new branch. And lets say that new branch has a bug that crashes the applicaiton. It is ok becasue we have the main branch which is still working. 

How to create a local branch?
git checkout -b branch_name

How to create a remote branch? (always make it the same name as the local)
git push origin -u branch_name

How to navigate to another branch?
git checkout branch_name

How to name a branch?
I usually try to name the branch by doing: feat/movement (feat = feature)
It is concise and reminds me why I made this branch and what I am trying to do

How to delete a local branch?
git branch -d branch_name

How to delete a remote branch?
git push origin --delete branch_name

Since you know what branching is and why we do it, now lets go over pushing your changes.

When you are ready to push changes, this is how the flow goes:
git add .
git commit -m "put a message here describing what changes you made"
git push origin branch_name

Always make sure you are pushing changes for every change you make, even as simple as delete code. 


How to pull code from a remote branch to you local branch?
Make sure you are in the correct local branch then:
git pull origin branch_name



We can discussing merging and rebasing later (cuz i am still lowkey trying to master it);
