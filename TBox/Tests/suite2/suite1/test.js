alert("Hello from siute1!");
Box.StartApp("C:/Windows/SYSTEM32/mspaint.exe");
Box.SetOnTop("Untitled - Paint");
Box.SetMousePos(300,300);
Box.MouseDown(0);
Box.MouseMove(600,600, 5);
Box.MouseUp(0);
Box.CloseApp();
Box.PrintScreen("D:/1.jpg");
Box.Log('Hello from main siute!');