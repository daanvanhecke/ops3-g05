#!/bin/bash

siege -c10 -d10 -t5M
siege -c20 -d10 -t5M
siege -c40 -d10 -t5M
siege -c80 -d10 -t5M
siege -c160 -d10 -t5M