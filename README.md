# Qualifizierung verschiedener Temperatursensoren

Diese Repository nutze ich zur Ablage von Ergebnissen und Daten meiner Untersuchungen zu verschiedenen Temperatursensoren.

Im wesentlichen geht es bei den Untersuchungen um die Aufnahme von Kalibrierkennlinien verschiedener Sensoren. Mit diesen werden die Messdaten in weiteren Charakterisierungen verrechnet um so eine Aussage über die zu erreichenden Genauigkeiten zu erhalten.


## Sensoren
Untersucht werden folgende Sensoren:
* PT100 (4-draht an ALMEMO)
* NTC (4-draht an ALMEMO)
* DS18B20

### DS18B20 Fälschungen
Gerade die im DIY Bereich gern verwendetet DS18B20 in der fertig konfektionierten Ausführung mit Tauchhülse und Kabel sind leider meist Fälschungen. Was von diesen zu erwarten ist und was nicht geht aus der nachfolgenden Untersuchung hervor. Die im Repo mit B1 Clone klassifizierten Sensoren und natürlich das Original (A1 Authentic Maxim DS18B20) sollen Teil meiner Qualifizierung sein.

* [counterfeit_DS18B20](https://github.com/cpetrich/counterfeit_DS18B20) (von [cpetrich](https://github.com/cpetrich))

## Aufbau
Herzstück des Aufbaus ist ein Blockkalibrator, welcher als hochgenaue Temperaturquelle dient. Das zur verfügung stehende Modell [Fluke 9170](https://www.fluke.com/de-de/produkt/kalibratoren/temperaturkalibratoren/fluke-calibration-9170) erreicht eine Stabilität von ±0,005 °C. Als Referenz kommt ein kalibrierter PT100 Sensor in Verbindung mit einem ALMEMO Präzisionsmessgerät zum Einsatz.
![Versuchsaufbau mit Fluke Blockkalibrator](/Docu/IMG_0576.jpeg)

### Temperaturverlauf
#### Abgleich mit DS18B20 im Bereich von 0 - 105 °C (8 Stützstellen)
![Temperature diagram](/Runs/004/temperature_diagram.png)

##### 75 °C Stützstelle im Detail
![Temperature diagram detail @ 75 °C](/Runs/004/temperature_diagram_detail75.png)

##### DUT Error
![DUT Error](/Runs/004/dut_error.png)


## Ziel der Untersuchung
Ich möchte meine eigenen Temperatursensoren aufbauen. Diese sollen als inteligente Sensoren ausgeführt werden, also ein bereits mit der Kalibrierkennlinie verrechnetes Temperatursignel (digital) ausgeben.

![Erster CAD Entwurf eines Tri-Clamp Sensors](Engineering/ASY_Thermowell_50_v2.jpeg)
Erster CAD Entwurf eines Tri-Clamp Sensors
