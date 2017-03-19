from flask import Flask, render_template
from flask_script import Manager
app = Flask(__name__, template_folder='templates')

app.debug = True
app.secret_key = 'development key'
app.config['TEMPLATES_AUTO_RELOAD'] = True

manager = Manager(app)

@app.route('/')
def index():
    return render_template('index.txt')

if __name__ == '__main__':
    manager.run()

