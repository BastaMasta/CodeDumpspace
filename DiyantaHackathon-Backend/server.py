import paho.mqtt.client as mqtt
import time
import json
import random

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)

# Set-up pre-set variables

sense_stations = {"lucknow":True, "Varanasi": True, "Patna":True}

station_stat = {"lucknow":0, "Varanasi": 0, "Patna":0}

request_codes = {'0':'Sensor Ping','1':'Sensor Data','2':'Satellite Data','3':'Weather Data',}

unacked_publish = set()

def on_connect(client, userdata, flags, rc, properties):
    print("Connected to MQtt Server!")
    print("Establishing connection to Satellite server...")
    print("Server connection established")

def on_disconnect(client, userdata, rc):
    print("Fatal Error! Disconnected from Server")

def on_publish(client, userdata, mid, reason_code, properties):
    # reason_code and properties will only be present in MQTTv5. It's always unset in MQTTv3
    try:
        userdata.remove(mid)
    except :
        print(mid)

def client_callback_requests(client, userdata, message):
    data = json.loads(message.payload.decode('utf-8'))
    print("recieved {2} request from client with client id {0} on with request code {1}".format( data["sender"], data["code"], request_codes[data["code"]]))
    # Recieved request code 0 -> Sensor Ping Request
    if str(data['code']) == '0':
        if sense_stations[data["location"]] :
            msg = "{"+"\"clientid\":\""+data["sender"]+"\",\"code\":0, \"resp\":\"1\""+"}"

    # receieved request code 1 -> Sensor Data Request
    elif str(data['code']) == '1':
        if sense_stations[data["location"]]:
            if station_stat[data["location"]] == 0:
                #Send Normal Data
                msg = "{"+"\"clientid\":\"{0}\",\"code\":\"1\", \"DO\":{1}, \"BOD\":{2}, \"fecal_coliform\":{3}, \"nitrate\":{4}, \"flow_rate\":{5}, \"ammonia\":{6}, \"phosphorous\":{7}, \"pH\":{8}".format(data["sender"],random.randrange(10,100), random.randrange(100,200),random.randrange(10,100), random.randrange(100,200),random.randrange(10,100), random.randrange(100,200), random.randrange(100,200), random.randrange(1,15)) + "}"
            else:
                #Send Polluted Data
                msg = "{"+"\"clientid\":\"{0}\",\"code\":\"1\", \"DO\":{1}, \"BOD\":{2}, \"fecal_coliform\":{3}, \"nitrate\":{4}, \"flow_rate\":{5}, \"ammonia\":{6}, \"phosphorous\":{7}, \"pH\":{8}".format(data["sender"],random.randrange(10,100), random.randrange(100,200),random.randrange(10,100), random.randrange(100,200),random.randrange(10,100), random.randrange(100,200), random.randrange(100,200), random.randrange(1,15)) + "}"

    # Recieved request code 2 -> Satellite Data Request
    elif str(data['code']) == '2':
        if station_stat[data["location"]] == 0:
                #Send Normal Data
            msg = "{"+"\"clientid\":\"{0}\",\"code\":\"2\", \"ph\":{1}, \"salinity\":{2}, \"turbidity\":{3}, \"laand_surface_temperature\":{4}, \"suspended_matter\":{5}, \"DOM\":{6}, \"DO\":{7}, \"chlorophyll\":{8}".format(data["sender"],random.randrange(10,100), random.randrange(100,200),random.randrange(10,100), random.randrange(100,200),random.randrange(10,100), random.randrange(100,200),random.randrange(10,100), random.randrange(100,200)) + "}"
        else:
                #Send Polluted Data
             msg = "{"+"\"clientid\":\"{0}\",\"code\":\"2\", \"ph\":{1}, \"salinity\":{2}, \"turbidity\":{3}, \"laand_surface_temperature\":{4}, \"suspended_matter\":{5}, \"DOM\":{6}, \"DO\":{7}, \"chlorophyll\":{8}".format(data["sender"],random.randrange(10,100), random.randrange(100,200),random.randrange(10,100), random.randrange(100,200),random.randrange(10,100), random.randrange(100,200),random.randrange(10,100), random.randrange(100,200)) + "}"

    # Recieved request code 3 -> Weather Data Request
    elif str(data['code']) == '3':
        msg = "{"+"\"clientid\":\"{0}\",\"code\":\"3\", \"rainfall\":{1}".format(data["sender"], random.randrange(10,100)) + "}"

    else:
        print("Invalid request code")
        return None

    # Publish the Message on the response channel
    msg_inf = client.publish('client/response', msg, qos=1)
    print("response published with MID:", end=" ")

def change_pol_status(client, userdata, message):
    changer = message.payload.decode('utf-8')
    station_stat[changer] != station_stat[changer]
    

client.on_connect = on_connect
client.on_disconnect = on_disconnect
client.on_publish = on_publish

client.message_callback_add('server/requests', client_callback_requests)
client.message_callback_add('server/admin', change_pol_status)


client.connect("192.168.43.221", 1883)

client.subscribe("server/requests")
client.subscribe("server/admin")

client.loop_forever()
