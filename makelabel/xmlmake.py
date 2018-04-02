#-*ctf-8*-
import glob
import  os
from PIL import Image, ImageTk
s1="""    <object>
        <name>{0}</name>
        <pose>Unspecified</pose>
        <truncated>0</truncated>
        <difficult>0</difficult>
        <bndbox>
            <xmin>{1}</xmin>
            <ymin>{2}</ymin>
            <xmax>{3}</xmax>
            <ymax>{4}</ymax>
        </bndbox>
    </object>"""

s2="""<annotation>
    <folder>VOC</folder>
    <filename>{0}</filename>
    <source>
        <database>My Database</database>
        <annotation>VOC</annotation>
        <image>flickr</image>
        <flickrid>NULL</flickrid>
    </source>
    <owner>
        <flickrid>NULL</flickrid>
        <name>LK</name>
    </owner>
    <size>
        <width>{1}</width>
        <height>{2}</height>
        <depth>3</depth>
    </size>
    <segmented>0</segmented>
    <object>
        <name>{3}</name>
        <pose>Unspecified</pose>
        <truncated>0</truncated>
        <difficult>0</difficult>
        <bndbox>
            <xmin>{4}</xmin>
            <ymin>{5}</ymin>
            <xmax>{6}</xmax>
            <ymax>{7}</ymax>
        </bndbox>
    </object>{8}
</annotation>
"""

textlist=glob.glob('./labels\\*.txt')
for text_ in textlist:
    filename=os.path.split(text_)[-1].split('.')[0]
    imgname=filename+".tif"
    picturepath="./images/"+imgname
    pil_image = Image.open(picturepath)
    w0,h0=pil_image.size
    savename="./XML/"+filename+".xml"
    flabel = open(text_, 'r')
    lb = flabel.readlines()
    flabel.close()
    ob2 = ""
    if len(lb)<2:
        continue  # no annotation
    x1=lb[1].split(' ')
    print x1
    x2 = [i for i in x1]
    if len(lb)>2:  # extra annotation
        for i in range(2,len(lb)):
            y1 = lb[i].split(' ')
            y2 = [i for i in y1]
            ob2+='\n' + s1.format(y2[4].strip('\n'),y2[0],y2[1],y2[2],y2[3])
   # imgname=('%06d' % (int(text_[13:-4])))+'.jpg'
  #  savename='Annotations\\'+str('%06d' % (int(text_[13:-4])))+'.xml'
    print imgname,savename
    f = open(savename, 'w')
    ob1=s2.format(imgname,w0,h0, x2[4].strip('\n'), x2[0],x2[1],x2[2],x2[3],ob2)
    f.write(ob1)
    f.close()