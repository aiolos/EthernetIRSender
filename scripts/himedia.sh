#!/usr/bin/env bash

# Receiver On
curl -o /dev/null http://192.168.38.177/?code=A55A58A7\&p=2\&r=5\&f=40\&d=20 &
# TV On
curl -o /dev/null http://192.168.38.177/?code=E0E09966\&p=3\&r=1 &
# Receiver STB input
curl -o /dev/null http://192.168.38.177/?code=A55A3AC5\&p=2\&r=3\&f=40\&d=20 &
# Samsung HDMI3
curl -o /dev/null http://192.168.38.177/?code=E0E043BC\&p=3\&r=1 &