using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using UnityEngine;
using UnityEngine.UI;

public class TestComm : MonoBehaviour
{
    public string portName = "COM4";
    public GameObject btn;

    private SerialPort nano_tx;
    private float t = 0;
    private string on = "1", off = "0";
    private bool disableBtn = true;
    // Start is called before the first frame update
    void Start()
    {
        // Init the Serial stream
        nano_tx = new SerialPort(portName, 9600);
        nano_tx.Open();
    }

    // Update is called once per frame
    void Update()
    {
        t += Time.deltaTime;
        if (t > 0.1)
        {
            if (nano_tx.IsOpen && disableBtn)
            {
                // To avoid Serial port Overflow

                t = 0;
                if (Input.GetKey("1"))
                {
                    nano_tx.Write(on);
                    btn.GetComponent<Image>().color = Color.green;
                    //Debug.Log(1);
                }
                else
                {
                    nano_tx.Write(off);
                    btn.GetComponent<Image>().color = Color.white;
                    //Debug.Log(0);
                }

            }
        }
    }

    public void OnBtn()
    {
        disableBtn = !disableBtn;
        if (!disableBtn)
        {
            //Debug.Log("Always On");
            nano_tx.Write(on);
            btn.GetComponent<Image>().color = Color.green;
        }
        else
        {
            //Debug.Log("Waiting for the key '1'");
            nano_tx.Write(off);
            btn.GetComponent<Image>().color = Color.white;
        }
    }
}
