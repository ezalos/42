/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Navigation.js                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:20:56 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/30 17:51:38 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Navigation/Navigation.js

import { createStackNavigator, createAppContainer } from 'react-navigation'
import Search from '../Components/Search'
import FilmDetail from '../Components/FilmDetail'

const SearchStackNavigator = createStackNavigator({
	Search: { // Ici j'ai appelé la vue "Search" mais on peut mettre ce que l'on veut. C'est le nom qu'on utilisera pour appeler cette vue
      screen: Search,
      navigationOptions: {
        title: 'Rechercher'
      }
  },
    SideList: { // Ici j'ai appelé la vue "Search" mais on peut mettre ce que l'on veut. C'est le nom qu'on utilisera pour appeler cette vue
      screen: SideList,
      navigationOptions: {
        title: 'SideList'
      }
  },
  FilmDetail: { // Encore une fois j'ai mis le même nom que celui du component mais libre à vous de choisir un nom différent
    screen: FilmDetail
  }
})

export default createAppContainer(SearchStackNavigator)
