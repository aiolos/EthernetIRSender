#!/usr/bin/env bash
# DAB+ on
curl -o /dev/null http://192.168.1.177/?code=40BFC837\&p=2\&r=1
# receiver on
curl -o /dev/null http://192.168.1.177/?code=A55A58A7\&p=2\&r=5\&f=40\&d=20
# DAB+ preset 3
curl -o /dev/null http://192.168.1.177/?code=40BF827D\&p=2\&r=1
# receiver A AUX
curl -o /dev/null http://192.168.1.177/?code=A55AF20D\&p=2\&r=3\&f=40\&d=20
