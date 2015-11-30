<div style="width:800px; margin:0 auto;">

<img src="img/shopbot/shopbot.png" width= "200"/>

<div align="right" style="margin-right:3%"><font color="red"><big>Wear safety glasses and closed-toe shoes</big></font><right><img src="img/shopbot/safety.png" width= "100"/></right>
</div>

### Indroduction
<div align="justify" style="margin-left:2.5%" style="margin-right:3%">

The Shopbot is a CNC Machine that can operate milling, drilling of materials like wood, acrylic and even soft metals. it can use both in 2D and 3D machining operations.

<center><img src="img/shopbot/1.JPG" width= "800"/></center>


</div>

### Working
<div align="justify" style="margin-left:2.5%" style="margin-right:3%">

Step 1: Creating the toolpath



Open your 2D design file .DXF fie using the Vcarve Pro software. 



<center><img src="img/vcurve/1.png" width= "700"/></center>



Set the Job size of the material based on the available dimensions available on the board you are cutting. The material(Z) thickness is taken as 12mm (depending on the plywood sheet). select the Z Zero on top edge of matirial, Then XY Datucm position seect. Be careful to uncheck the “offset” option.

<center><img src="img/vcurve/v1.png" width= "180"/> <img src="img/vcurve/v1.1.png" width= "470"/></center>


Click on the tool path option onthe right corner of the window.you can see the tool opertion optins window. Pin it there down so that it doesn’t move.

<center><img src="img/vcurve/2.png" width= "700"/></center>

There are primarily three operations that can be done using the ShopBot: <b> Drilling, pocket and profile </b> 

<center><img src="img/vcurve/toolop.png" width= "200"/></center>

Select the drill you use for commen operations or you can use diffrent tool for diffrent operation. So you can adjest the tool propertis speed, depth of cut at each layer, spidile speed etc.

<center><img src="img/vcurve/selectdrill.png" width= "400"/></center>


#### Drilling

First we start with the Drill operation to mark the holes for the portions which we want to drill screws for the object firmly held in place. Use the circle tool to draw circles of diameter 3mm on opposite sides of each piece of the design.Then select the circles drawn yellow and   Set the Start depth as 0 and Cut depth as 6mm. And from the Tool End section, click on “Select”.


<center><img src="img/vcurve/drill1.1.png" width= "400"/> <img src="img/vcurve/drill1.png" width= "180"/></center>

Set the diameter for the tool as 6.35mm and the Pass Depth (the depth at which each cut is done) as 3.5mm. The Spindle Speed can be set to 12,000 rpm and you can use higher speeds for better finish.

Now click on “Preview selected toolpath” to watch the simulation of the drilling being done on the material. Next, click on the “Save” button to save the toolpath


#### Pocket

Next, select the circular portion of the design of which you want to remove only the top few layers and unselect everything else. Click on the “Pocket” button and set the cut depth to 8mm. Set the stepover (radius of the smallest circle of which the machine removes the material) as 1.5mm.

<center><img src="img/vcurve/pocket1.png" width= "500"/></center>


Then click on “Preview selected toolpath” to view the simulation of the engraving or material removal. If you are satisfied, click on the Save button to save the toolpath.


#### Profile tools

This operation is used to cut a portion of the material from the whole board. Select the lines which you wish to cut and click on the Profile button. Set the Cut Depth to 14mm and save the tool pathh. You can then later view the preview for the operation on the ShopBot, like a simulation.
preview the all toolpaths.

<center><img src="img/vcurve/preview2.png" width= "350"/> <img src="img/vcurve/preview2.1.png" width= "200"/></center>

Now save the dirlling toolpath operation sepratly.the pocket and profile toolpaths together. The order should be: Drill→ Pocket → Profile.


<center><img src="img/vcurve/drill.png" width= "700"/></center>
<center><img src="img/vcurve/profile-milling.png" width= "700"/></center>



<center><img src="img/shopbot/5.JPG" width= "400"/></center>

</div>

### safty reqirements
<div align="justify" style="margin-left:2.5%" style="margin-right:3%">


<center><img src="img/shopbot/4.JPG" width= "400"/></center>
</div>

</div>