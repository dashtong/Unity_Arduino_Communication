# Communication between Unity and Arduino
## Setup
1. Adding a C# script in Unity
2. Adding `using System.IO.Ports` in the heading
    - If `System.IO.Ports` is not included in the project, in Visual Studio, right click Solution > Manage NuGet Package... > Install  `System.IO.Ports`
3. In Unity, Edit > Project Settings > Player > Other Settings > Configuration > Api Compatibility Level > .NET 4.x
4. Now you can successfully declare SerialPort in the script.

## Hardware setup
![](https://i.imgur.com/Dgpa9My.jpg)
