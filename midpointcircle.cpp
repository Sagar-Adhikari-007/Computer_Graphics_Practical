    #include<graphics.h>
    #include<conio.h>
    #include<dos.h>

    void circlepoints(int xc,int yc,int x, int y,int val)
    {
        putpixel(xc+x,yc+y,val);
        putpixel(xc+y,yc+x,val);
        putpixel(xc+y,yc-x,val);
        putpixel(xc+x,yc-y,val);
        putpixel(xc-x,yc-y,val);
        putpixel(xc-y,yc-x,val);
        putpixel(xc-x,yc+y,val);
        putpixel(xc-y,yc+x,val);
    }

    void midpointcircle(int xc,int yc,int r)
    {
        int x=0,y=r,pk;
        pk=1-r;
        circlepoints(xc,yc,x,y,15);
        while(x<y)
        {
            if(pk<0)
            {
                pk=pk+2*x+1;
            }
            else
            {
                y=y-1;
                pk=pk+2*x-2*y+1;
            }
            x=x+1;
            circlepoints(xc,yc,x,y,15);
        }
    }

    void main()
    {
        int gd =DETECT;
        int gm;
        initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
        midpointcircle(100,100,50);
        getch();
        closegraph();
    }