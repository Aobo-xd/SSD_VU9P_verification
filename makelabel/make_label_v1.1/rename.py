import os;
def rename():
    count=0
    path="F:\\picture\\msk";
    filelist=os.listdir(path);
    for files in filelist:
        Olddir=os.path.join(path,files);
        if os.path.isdir(Olddir):
            continue;
        filename=os.path.splitext(files)[0];
        filetype=os.path.splitext(files)[1];
        namecount='%d_msk'%count
        Newdir=os.path.join(path,str(namecount)+filetype);

        os.rename(Olddir,Newdir);
        count=count+1;


rename();