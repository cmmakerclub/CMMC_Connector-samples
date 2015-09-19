// Copyright Nat Weerawan 2015-2016
// MIT License

PubSubClient::callback_t on_message_arrived = 
[&](const MQTT::Publish & pub) -> void {
    String topic = pub.topic();
    String payload = pub.payload_string();
    String text = topic + " => " + payload;

  if (payload == "00") {
    digitalWrite(RELAY1, OFF);
  }
  else if (payload == "01") {
    digitalWrite(RELAY1, ON);
  }
  else if (payload == "10") {
    digitalWrite(RELAY2, OFF);
  }
  else if (payload == "11") {
    digitalWrite(RELAY2, ON);
  }
  else if (payload == "OFF") {
    digitalWrite(RELAY2, OFF);
    digitalWrite(RELAY1, OFF);
  }
  else if (payload == "ON") {
    digitalWrite(RELAY2, ON);
    digitalWrite(RELAY1, ON);
  }  
 };
