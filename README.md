# IoT-Based-Smart-Hand-Sanitizer-Dispencer-(COVID-19)-

## Abstract
In spite of the advancements in the health department, the Coronavirus has proved to be an invisible enemy for which the world was not ready. The virus has primarily spread through contact and respiratory droplets. Hand sanitizing and wearing a mask are the most common ways to avoid the transmission of the infection and prevent people from becoming infected. At public places like general stores or banks, it has been noticed that 1 or 2 people are specifically appointed to check body-temperature, face mask and to sanitize the visitor's hand before entering into the province. They have to sanitize the visitor's hand manually using pressure bottles and check their body temperature using a temperature gun. This adds to the risk of the disease spreading as the appointed person comes in contact with many people throughout the day while doing their job, and sometimes they fail to do these tasks accurately. Hence there is an urgent requirement of such a device which can perform these tasks accurately and without human interference. This will surely make people's lives easy and will even keep them safe from diseases. THIS SMART HAND SANITIZER DISPENSER automates the job done by the appointed person without human interference. It dispenses the sanitizer and checks the body temperature automatically. This is achieved using an Ultrasonic sensor and MLX90614 temperature sensor, respectively. All the sensors and actuators are connected to a microcontroller which acts as the brain of the device. Furthermore, it also detects whether the customer(human) is wearing a mask or not. If not, he/she would not be allowed inside the shop, or the gates to the shop will not open. OpenCV is used to detect the face real-time, and then the classification is done using a Convolutional Neural Network. Finally, the data is stored on the cloud, which can be later used for research purposes. All this has been implemented successfully.  

## Introduction
In early 2020, after December 2019 a new kind of virus was found in China. SARS-CoV-2 has been recognized by the World Health Organization as a new form of coronavirus. The epidemic has spread all over the world. COVID-19 is caused by SARS-CoV-2, which induces inflammation of the respiratory tract. It affects the upper respiratory tract (nose and throat) or lower respiratory tract of a human (windpipe and lungs). The virus is primarily spreading through respiratory droplets and contact. Hand sanitizing and wearing a mask are the most common ways to avoid the transmission of the infection and prevent people from becoming infected. Because of this, the demand for hand sanitizers has increased. Alcohol-based hand sanitizers are applied by spraying the solvent as one presses a pump with one hand. This allows more people to come into touch with the pump’s handle, which raises the likelihood of viral transmission. Also, there are dispensers where people have to work with their feet, but pressing them is irritating, and often people walk by without disinfecting their hands. In addition, the use of sanitizers varies with humans, making it impossible to estimate the level of use and handle refills and substitutes. 
Because of this reason, the use of hand sanitizers is limited, which does not prevent the transmission of the virus. There are places where there is a person appointed to dispense the sanitizer outside a restaurant, café, grocery shop etc. He/she checks your temperature using the temperature gun and also dispenses the sanitizer manually. This is very risky as the appointed person comes in contact with many people throughout the day. These types of equipment (pressure bottles and temperature gun) are handled physically by more than one person throughout the day, leading to physical contact between them. Hence there is an urgent requirement of a device which can do this work automatically and effectively. This device will eliminate the problem of human interference and will make hand sanitization safe and comfortable.  

## Proposed System 
The proposed method is a more practical and elegant approach to the conventional way of sanitizing your hand in public areas. This product dispenses the same amount of sanitizer every time. It uses an ultrasonic sensor to detect the hand and then dispenses the sanitizer. Furthermore, there are two additional features: Face mask recognition and temperature detection. Hence whenever a person sanitizes his/her hand our product will automatically check whether or not the person is wearing a mask and also measure his/her body temperature and simultaneously will upload the data on the cloud. As the temperature of the customer is being measured, in the future, the data can be useful for monitoring the health of the person and may also be useful for future studies. There is also an interrupt button. If the system runs into an error the user can reset it by pressing the interrupt button. The whole system is contactless and hence very user friendly. 

## Methodology 
The proposed system follows a procedure to generate the results. Taking an example of deploying this dispenser outside a general store, first task it will perform is to sanitize the visitors hand without any physical contact before entering into premises as the automatic door wont open until the dispenser commands. Simultaneously it will perform 2 tasks which are checking the body temperature of the visitors using an Infrared temperature sensor through their wrist and detecting the face mask using deep learning based face mask detection algorithm. After performing these 3 tasks, the visitor would be allowed to enter depending upon the temperature value and the presence of mask. Lastly, it will gather all the results and upload it on the cloud thus maintaining a database for further use. The defaulter may be asked to wear a mask or see a doctor as his/her body temperature is not in the expected range.

## Hardware implementation
* Arduino Uno: The proposed device uses Arduino Uno, a microcontroller board based on ATmega328P. It has 14 optical input/output pins and 6 analog inputs, and a 16 MHz ceramic resonator (CSTCE16M0V53-R0), A USB link, a power port, an ICSP header and a reset key. The 0-12 digital pins and A0 (analog) pin were used to read the value of the temperature sensor. The Arduino Uno serves as a central core for all of the modules. In this unit, it serves as an interface that links all other components such as the ultrasonic sensor, LCD, temperature sensor and the ESP8266 module. RTOS is not needed for this device hence its On-Chip RAM and ROM are sufficient to carry out the tasks Arduino Uno with its performance and low cost is a better fit for the proposed device.  

* Ultrasonic Sensor: The proposed device uses ultrasonic sensors to track the palm. Since they are not influenced by smoke or other invisible materials, they are favoured over infrared sensors. After configuring the ultrasonic sensor, the pulseIn() feature is used to read the value (travel time) and assign the value to the duration vector. Using this function, the ultrasonic sensor will measure the distance between the customer's hand and the nozzle. The threshold was set for 25cm. Hence whenever a person brings his hand in the range of the ultrasonic sensor the dispenser dispenses the sanitizer. 
ESP8266: The ESP8266 is a Wi-Fi module that has a System On a Chip incorporated with the TCP/IP protocol stack that can allow any microcontroller access to your Wi-Fi network. It is also able to host and unload all Wi-Fi networking functionality from another application processor. It is preprogrammed and comes with the firmware package for the AT command. So, anybody can just attach it to the Arduino system and get the Wi-Fi Ability. Hence using this all the real-time data of the proposed system are uploaded to the cloud. 

* MLX90614: MLX90614 is a digital temperature sensor using contactless infrared (IR) sensor. It is used to monitor and measure body temperatures ranging from-70°C to 382°C. It uses IR rays so that it can measure body temperature without any physical interaction and interacts with the microcontroller using the I2C protocol. It is a contactless sensor with very high accuracy. Thanks to its high accuracy and precision, it is often used in a wide variety of industrial, health and household applications such as room temperature control, body temperature assessment, etc. 
Figure 42.6,42.7,42.8 shows a custom-designed 3D printed model of the dispenser. It has dedicated places for different components of the dispenser, a camera, nozzle ultrasonic and temperature sensor. 

## Software Implementation
* Face detection: Face detection: For face detection, OpenCV is used OpenCV. It provides the basic infrastructure for computer vision applications. To convert the images into grayscale images and also to resize the images into the size of 100x100 OpenCV is used. Hence first all the images are converted into 100*100-pixel size. Simultaneously they are converted into greyscale images as color is not important to detect the face mask. Figure 42.9 shows this process. After resizing the images, normalizing the images by dividing their size by 255 to convert them into 0 and 1.

* These Images then used to train the neural network. As the neural network needs a 4-Dimensional Array, Dimensional information of each image is converted to a 4 Dimensional array by adding 1 as these are grey scale images.


## Convolution Neural Network Architecture
* Using Convolution Neural Network to decide with a mask or without a mask. Using 2 convolutional layers first one having 200 (3*3) kernels and the second layer is having 100 (3*3) kernels. Then these layers are flattened, and hence a new layer is created. A dropout layer is used to reduce the overfitting. Then finally it is connected to a dense layer of 50 neurons and at the last, the output layer has 2 neurons (with a mask and without a mask). After the first and second layers, ReLU Layer (Rectified Linear Unit) and a pooling layer are used. The ReLU layer is a piecewise linear function which acts as the activation function. It gives the output directly if the input is having a value greater than 0 i.e. positive and the pooling layer is used to reduce the number of parameters and computation in the network. The data is split into testing and training, 30% and 70% respectively. After the splitting, the models are trained. 25 models (epochs) were trained. After compiling the models checkpoints were created to save the models. The models having validation loss greater than a specific value were chosen and hence the best models were saved. 
* As mentioned earlier, 25 models (epochs) were trained. In Graph1 training loss is the loss or the inaccuracy while training the model. Hence as more and more no of models were trained this value kept decreasing. On the other hand, validation loss is inaccuracy while testing. The validation loss is more important than the training loss.  The figure 42.12 shows for the 9th, 17th and 19th model (epoch) the validation loss is the least compared to other values. Also, in Graph 2 the training accuracy and the testing accuracy are plotted. When the models were compared, 17th model has the maximum validation accuracy or testing accuracy of 94.93%. The execution time for the model was 1 minute 214 milliseconds per step with a loss of 0.1887. Figure 42.14 shows the output.













Paper available at : https://drive.google.com/file/d/1qcUOE-HdOTZPRiFFslAAejRB80ydhQt0/view?usp=sharing












Datasets https://drive.google.com/drive/folders/1fs2-vaO2T01V-g6w6l18tQD0tuI7fmtS?usp=sharing

Tinkercad https://www.tinkercad.com/things/33GHexLPtPE

Colab link https://colab.research.google.com/drive/1FkY34IKlSJQih96nu9Ny3J6Twz1T3emY?usp=sharing

<img src="https://github.com/Kaizenick/IoT-Based-Smart-Hand-Sanitizer-Dispencer-COVID-19-/blob/main/Images/pic1.png" width="40%"><br />
schematic diagram of IOT based smart contactless hand sanitizer dispenser<br />
<img src="https://github.com/Kaizenick/IoT-Based-Smart-Hand-Sanitizer-Dispencer-COVID-19-/blob/main/Images/pic6.png" width="40%"><br />
3D printed model of the dispenser with camera, ultrasonic sensor, temperature sensor and nozzle<br />
<img src="https://github.com/Kaizenick/IoT-Based-Smart-Hand-Sanitizer-Dispencer-COVID-19-/blob/main/Images/pic9.png" width="40%"><br />
Schematic of the Convolutional Neural network (CNN)<br />
<img src="https://github.com/Kaizenick/IoT-Based-Smart-Hand-Sanitizer-Dispencer-COVID-19-/blob/main/Images/pic10.png" width="40%"><br />
Epochs vs Loss<br />
<img src="https://github.com/Kaizenick/IoT-Based-Smart-Hand-Sanitizer-Dispencer-COVID-19-/blob/main/Images/pic11.png" width="40%"><br />
Epochs vs Accuracy<br />
<img src="https://github.com/Kaizenick/IoT-Based-Smart-Hand-Sanitizer-Dispencer-COVID-19-/blob/main/Images/pic12.png" width="40%"><br />
Face mask detection <br />
<img src="https://github.com/Kaizenick/IoT-Based-Smart-Hand-Sanitizer-Dispencer-COVID-19-/blob/main/Images/pic13.png" width="40%"><br />
Block diagram for sending data to Thingspeak<br />
<img src="https://github.com/Kaizenick/IoT-Based-Smart-Hand-Sanitizer-Dispencer-COVID-19-/blob/main/Images/pic14.png" width="40%"><br />
Software and their different channels reading.<br />

## Conclusion and Future works
A brand-new system has been developed having four applications, the primary one being the automatic sanitizer dispenser and the others being temperature detection, facemask detection system and data aggregation system This will lead to a consistent and healthy sanitizing experience for both the customer and the store owner.. The SMART HAND SANITIZER DISPENSER sanitizes the customer’s hands without any physical contact. It eliminates the need for a person to sanitize customers' hands. Hence it also reduces the risk of disease transmission. The IoT Based system consists of an Arduino Uno, and several other secondary components are linked to it, such as: A camera, temperature sensor and ESP8622 Wi-Fi module. The ultrasonic sensor and the temperature sensor are mounted on the body of the dispenser. As the customer's hands are detected by the ultrasonic sensor, the dispenser dispenses the same amount of sanitizer each time. Simultaneously it checks the hand temperature and looks for the mask on the customers face. All this information is uploaded on the cloud. If the face mask is not detected the door to the shop is not opened in other words, the customer is not allowed to enter the shop. The cloud data can be accessed by a mobile or a computer and it can be used for further studies. If there is any problem with the dispenser the interrupt button can be used to reset the machine. 
Owing to lack of time and experience, several diverse modifications, studies and experiments have been left for the future. Future studies concerns a closer study of existing processes, new ideas to explore alternative approaches, or merely curiosity.

## The following are few areas for future research: 
* A new feature can be added to check social distancing among users.
* The device can also do face recognition of users and can only permit those users to enter into the province who are allowed. 
* The barcode scanner can be attached with the chassis to scan the user's Aarogya setu pass.
* The information collected about the user or customer can be further used to analyze and can also be sent immediately to the nearest medical store for further aid.
* Also name and number of the user can be added into the database. 

