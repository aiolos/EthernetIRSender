#!/usr/bin/env bash

# DAB+ Off
curl -o /dev/null http://192.168.38.177/?code=40BFC837\&p=2\&r=1 &
# Pioneer Off
curl -o /dev/null http://192.168.38.177/?code=A55AD827\&p=2\&r=5\&f=40\&d=20 &