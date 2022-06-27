import './index.scss';

import {sayHi} from '../lib/es6_global/src/index.bs.js';

function component() {
  const element = document.createElement('div');

  element.innerHTML = sayHi();

  return element;
}

document.body.appendChild(component());
