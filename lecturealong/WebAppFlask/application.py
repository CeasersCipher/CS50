from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/zack")
def zack():
    return render_template("zack.html")

@app.route("/login")
def login():
    return render_template("login.html")