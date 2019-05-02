/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configureStore.js                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:58:46 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/29 10:58:48 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Store/configureStore.js

import { createStore } from 'redux';
import toggleFavorite from './Reducers/favoriteReducer'

export default createStore(toggleFavorite)
